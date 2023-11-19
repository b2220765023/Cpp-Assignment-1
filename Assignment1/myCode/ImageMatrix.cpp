#include "ImageMatrix.h"
#include <iostream>


// Default constructor
ImageMatrix::ImageMatrix(){
    
}

// Parameterized constructor for creating a blank image of given size
ImageMatrix::ImageMatrix(int imgHeight, int imgWidth) : height(imgHeight), width(imgWidth) {
    data = new double*[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new double[width];
    }
}

// Parameterized constructor for loading image from file. PROVIDED FOR YOUR CONVENIENCE
ImageMatrix::ImageMatrix(const std::string &filepath) {
    // Create an ImageLoader object and load the image
    ImageLoader imageLoader(filepath);

    // Get the dimensions of the loaded image
    height = imageLoader.getHeight();
    width = imageLoader.getWidth();

    // Allocate memory for the matrix
    data = new double*[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new double[width];
    }

    // Copy data from imageLoader to data
    double** imageData = imageLoader.getImageData();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; j++) {
            data[i][j] = imageData[i][j];
        }
    }
}

// Destructor
ImageMatrix::~ImageMatrix() {
    if (data) {
        for (int i = 0; i < height; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}

// Parameterized constructor - direct initialization with 2D matrix
ImageMatrix::ImageMatrix(const double** inputMatrix, int imgHeight, int imgWidth) : height(imgHeight), width(imgWidth){
    data = new double*[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new double[width];
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] = inputMatrix[i][j];
        }
    }
}

// Copy constructor
ImageMatrix::ImageMatrix(const ImageMatrix &other) : height(other.height), width(other.width) {

    data = new double*[height];
    for (int i = 0; i < height; ++i) {
        data[i] = new double[width];
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Copy assignment operator
ImageMatrix& ImageMatrix::operator=(const ImageMatrix &other) {

    if (data) {
        for (int i = 0; i < height; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    height = other.height;
    width = other.width;
    data = new double*[height];

    for (int i = 0; i < height; ++i) {
        data[i] = new double[width];
        for (int j = 0; j < width; j++) {
            data[i][j] = other.data[i][j];
        }
    }
    return *this;
}

// Overloaded operators

// Overloaded operator + to add two matrices
ImageMatrix ImageMatrix::operator+(const ImageMatrix &other) const {
    ImageMatrix result(height, width);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Overloaded operator - to subtract two matrices
ImageMatrix ImageMatrix::operator-(const ImageMatrix &other) const {
    ImageMatrix result(height, width);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Overloaded operator * to multiply a matrix with a scalar
ImageMatrix ImageMatrix::operator*(const double &scalar) const {
    ImageMatrix result(height, width);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; j++) {
            result.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return result;
}

// Getter function to access the data in the matrix
double** ImageMatrix::get_data() const {
    return data;
}

// Getter function to access the data at the index (i, j)
double ImageMatrix::get_data(int i, int j) const {
    return data[i][j];
}

int ImageMatrix::get_height() const {
    return height;
}

int ImageMatrix::get_width() const {
    return width;
}
void ImageMatrix::set_data(int row, int col, double value) {
    data[row][col] = value;
}
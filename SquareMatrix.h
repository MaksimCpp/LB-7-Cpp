class SquareMatrix {
private:
    int size;
    int** matrix;

    void allocateMemory() {
        matrix = new int*[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new int[size](); 
        }
    }

    void deallocateMemory() {
        if (matrix) {
            for (int i = 0; i < size; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }
    }

    void copyFrom(const SquareMatrix& other) {
        size = other.size;
        allocateMemory();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

public:
    SquareMatrix();
    ~SquareMatrix();
    void fillMatrix();
    int getSize() const;
    int determinant() const;
    void printMatrix() const;
    explicit SquareMatrix(int size);
    SquareMatrix(const SquareMatrix& other);
    SquareMatrix& operator=(const SquareMatrix& other);
};
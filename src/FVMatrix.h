#ifndef FVMATRIX_H
#define FVMATRIX_H

#include "Mesh.h"

//internal data
enum Solver {jacobi, gaussSidel, SOR};


class FVMatrix
{
    public:

        // Default constructor
        // normResidual - should contain the current normalized residual value
        // normResidualIni - should contain the current normalized residual value when the solver method was called
        // absNormResidual - maximum value allowed for the normResidual, if the normResidual < absNormResidual the iteration process should end
        // relNormResidual - minimum reduction required for the normResidual, if normResidual/normResidualIni < relNormResidual the iteration process should end
        FVMatrix(const Mesh& mesh, vector<double>& xVector, Solver solver, double absNormResidual, double relNormResidual, double solverParam = 0.);

        // Destructor
        virtual ~FVMatrix(){} ;

        // Member Functions
        inline double axMultiplicationNoDiagonal(const unsigned int& i);
        inline double axMultiplication(const unsigned int& i);
        inline double normalizedResidualValue();

        void createRandomaMatrixbVector();
        void printaMatrix(std::vector<double>& mat, int n, int m);
        
        std::vector<double> doJacobi();
        std::vector<double> doGaussSidel();
        std::vector<double> doSOR();  
        std::vector<double> solve();

    private:
        std::vector<double> aMatrix_;
        std::vector<double> bVector_;
        std::vector<double> xVector_;
        unsigned int nCells_;
        double absNormResidual_;
        double relNormResidual_;
        double normResidual_;
        double residualNormFactor_;
        double wSOR_;
        Solver selectedSolver_; 
        double normalizedResidualValue_;       

};

#endif
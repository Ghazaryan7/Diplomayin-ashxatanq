#include <iostream>
#include<vector>

struct triangle
{
    int m_a;
    int m_b;
    int m_c;
    triangle(int a, int b, int c) :m_a(a), m_b(b), m_c(c) {}
};
bool isaTriangle(const std::vector<std::vector<bool>>& m, int a, int b, int c)
{
    return (m.at(a).at(b) && m.at(b).at(c) && m.at(c).at(a));
}

bool indipendentTriangle(const triangle& t1, const triangle& t2)
{
    int k = 0;
    k += ((t1.m_a == t2.m_a) + (t1.m_a == t2.m_b) + (t1.m_a == t2.m_c));
    k += ((t1.m_b == t2.m_a) + (t1.m_b == t2.m_b) + (t1.m_b == t2.m_c));
    k += ((t1.m_c == t2.m_a) + (t1.m_c == t2.m_b) + (t1.m_c == t2.m_c));
    return k == 0 ? 1 : 0;
}

int main()
{

    int size;
    std::cout << "matrix.size = ";
    std::cin >> size;
    std::vector<std::vector<bool>> matrix(size);
    for (int i = 0;i < size;++i)
    {
        for (int j = 0;j < size;++j)
        {
            bool a;
            std::cin >> a;
            matrix.at(i).push_back(a);
        }

    }

    // for(int i = 0;i < size;++i)
    // {
    //   for(int j = 0;j < size;++j)
    //   {
    //       std::cout << matrix.at(i).at(j) << "  ";
    //   }
    //     std::cout << std::endl;
    // }

    std::vector<triangle> triangles;
    for (int i = 0;i < size;++i)
    {
        for (int j = i + 1;j < size;++j)
        {
            for (int k = j + 1;k < size;++k)
            {
                //std::cout << i << " " << j << " " << k <<std::endl;
                if (isaTriangle(matrix, i, j, k))
                {

                    triangles.push_back(triangle(i, j, k));
                }
            }
        }
    }

    for (int i = 0;i < triangles.size();++i)
    {
        std::cout << "triangle = " << triangles.at(i).m_a << "  " << triangles.at(i).m_b << "  " << triangles.at(i).m_c << std::endl;

    }

    std::vector<std::vector<bool>> triangleMatrix(triangles.size());
    for (int i = 0;i < triangleMatrix.size(); ++i)
    {
        triangleMatrix.at(i).resize(triangles.size());

    }
    for (int i = 0;i < triangleMatrix.size();++i)
    {
        for (int j = 0;j < triangleMatrix.at(i).size();++j)
        {
            if (indipendentTriangle(triangles.at(i), triangles.at(j)))
            {
                triangleMatrix.at(i).at(j) = 1;
                triangleMatrix.at(j).at(i) = 1;
            }
            else
            {
                triangleMatrix.at(i).at(j) = 0;
                triangleMatrix.at(j).at(i) = 0;
            }
        }
    }

    for (int i = 0;i < triangleMatrix.size();++i)
    {
        for (int j = 0;j < triangleMatrix.at(i).size();++j)
        {
            std::cout << triangleMatrix.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }




    return 0;
}
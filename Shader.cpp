#include"Shader.hpp"

Shader::Shader(const GLchar* Vpath, const GLchar* Fpath)
{
    std::string VertexCode;
    std::string FragmentCode;
    std::ifstream VertexFile, FragmentFile;

    try
    {
        VertexFile.open(Vpath);
        FragmentFile.open(Fpath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << VertexFile.rdbuf();
        fShaderStream << FragmentFile.rdbuf();

        VertexFile.close();
        FragmentFile.close();

        VertexCode = vShaderStream.str();
        FragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "FILE ERROR" << std::endl;
    }

    const GLchar* vShaderCode = VertexCode.c_str();
    const GLchar* fShaderCode = FragmentCode.c_str();

    GLint vertexshade, FragShade, SuccessV, SuccessF;

    vertexshade = glCreateShader(GL_VERTEX_SHADER);
    FragShade = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexshade, 1, &vShaderCode, NULL);
    glShaderSource(FragShade, 1, &fShaderCode, NULL);
    GLchar logV[512];
    GLchar logF[512];


    glCompileShader(vertexshade);
    glGetShaderiv(vertexshade, GL_COMPILE_STATUS, &SuccessV);

    glCompileShader(FragShade);
    glGetShaderiv(FragShade, GL_COMPILE_STATUS, &SuccessF);

    if (!SuccessF || !SuccessV)
    {
        glGetShaderInfoLog(vertexshade, 512, NULL, logV);
        glGetShaderInfoLog(FragShade, 512, NULL, logF);
        std::cout << logV << std::endl;
        std::cout << logF << std::endl;

    }

    GLint ShadeProg;
    GLint SuccessProg;
    GLchar logP[512];
    ShadeProg = glCreateProgram();

    glAttachShader(ShadeProg, vertexshade);
    glAttachShader(ShadeProg, FragShade);

    glLinkProgram(ShadeProg);
    glGetProgramiv(ShadeProg, GL_LINK_STATUS, &SuccessProg);
    if (!SuccessProg)
    {
        glGetProgramInfoLog(ShadeProg, 512, NULL, logP);
        std::cout << logP << std::endl;
    }
    program = ShadeProg;
}

void Shader::Use()
{
    glUseProgram(this->program);
}
#include "./include/Shader.h"

Shader::Shader(const QString& vertexShaderPath, const QString& fragmentShaderPath)
    : m_Program(QOpenGLShaderProgram())
{
    m_Program.create();
    m_Program.addShaderFromSourceFile(QOpenGLShader::Vertex, vertexShaderPath);
    m_Program.addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShaderPath);
    m_Program.link();

}

Shader::~Shader()
{
    m_Program.destroyed();
}
unsigned int Shader::GetUniformLocation(const char* name) const
{
    return m_Program.uniformLocation(name);
}

void Shader::SetUniformValue(const char* name, const QMatrix4x4& matrix)
{
    m_Program.setUniformValue(GetUniformLocation(name), matrix);

}

void Shader::SetUniformValue(const char *name, const QVector4D &vector)
{
    m_Program.setUniformValue(GetUniformLocation(name), vector);

}

void Shader::AddBuffer(VertexBuffer* vbo, const VertexBufferLayout &layout)
{
    vbo->bind();

     unsigned int offset = 0;
    const auto& elements = layout.GetElement();

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];

        m_Program.setAttributeBuffer(i, element.type, offset, element.count, layout.GetStride());
        m_Program.enableAttributeArray(i);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);

    }


}


void Shader::bind()
{
    m_Program.bind();

}

void Shader::unbind()
{
    m_Program.release();

}


//void Shader::SetUniformValue(const char* name, int& value)
//{
//    m_Program->setUniformValue(GetUniformLocation(name), value);
//}

//void Shader::SetUniformValue(const char* name, unsigned int& value)
//{
//    m_Program->setUniformValue(GetUniformLocation(name), static_cast<GLint>(value));
//}


  //  ShaderProgramSource source = ParseShader(vertexShader_path, fragmentShader_path);
    //    std::string vertexSource = ParseShader("/home/henry/Documents/Programming/Project/QT_Hydromotion/vertexShader.vert");
    //    const char* vertexShaderSource = vertexSource.c_str();
   /// m_RendererID = CreateShader(source.VertexSource, source.FragmentSource)



//Shader::Shader(const QString& vertexShaderPath, const QString& fragmentShaderPath)
//    : m_Program(new QOpenGLShaderProgram())
//{
//    m_Program->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexShaderPath);
//    m_Program->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShaderPath);
//    m_Program->link();

//  //  ShaderProgramSource source = ParseShader(vertexShader_path, fragmentShader_path);
//    //    std::string vertexSource = ParseShader("/home/henry/Documents/Programming/Project/QT_Hydromotion/vertexShader.vert");
//    //    const char* vertexShaderSource = vertexSource.c_str();
//   /// m_RendererID = CreateShader(source.VertexSource, source.FragmentSource)

//}


//ShaderProgramSource Shader::ParseShader(const std::string &vertexShaderPath, const std::string &fragmentShaderPath)
//{


//    std::ifstream vertexFile(vertexShaderPath);
//    std::ifstream fragmentFile(fragmentShaderPath);
//    std::stringstream vertexBuffer, fragmentBuffer;
//    vertexBuffer << vertexFile.rdbuf();
//    fragmentBuffer << fragmentFile.rdbuf();

//    //ShaderProgramSource shaderSource;
//    //shaderSource.VertexSource = vertexBuffer.str();
//    //shaderSource.FragmentSource = fragmentBuffer.str();
//    return {vertexBuffer.str(), fragmentBuffer.str()};
//}

//unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
//{



////    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
////    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
////    glCompileShader(vertexShader);

////    //    Create and compile the fragment shader
////    std::string fragmentSource = ParseShader("/home/henry/Documents/Programming/Project/QT_Hydromotion/fragmentShader.frag");
////    const char* fragmentShaderSource = fragmentSource.c_str();
////    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
////    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
////    glCompileShader(fragmentShader);


//}

//unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
//{
//    //    //    Create the shader program
//    //    GLuint shaderProgram = glCreateProgram();
//    //    glAttachShader(shaderProgram, vertexShader);
//    //    glAttachShader(shaderProgram, fragmentShader);
//    //    glLinkProgram(shaderProgram);

//    //    // Use the shader program
//    //    glUseProgram(shaderProgram);



//}

//unsigned int Shader::GetUniformLocation(const std::string &name)
//{
//    //    glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
//    //    GLuint projLocation = glGetUniformLocation(shaderProgram, "u_MVP");
//    //    glUniformMatrix4fv(projLocation, 1, GL_FALSE, glm::value_ptr(proj));
//    return m_Program->uniformLocation(name);

//}


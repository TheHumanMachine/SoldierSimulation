#include "GLSLProgram.h"
#include "Errors.h"
#include <fstream>


GLSLProgram::GLSLProgram() : _programID(0), _vertexShaderID(0), _fragmentShaderID(0)
{

}


GLSLProgram::~GLSLProgram()
{
}


void GLSLProgram::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0){
		fatalError("Vertex Shaders failed to be created!");
	}

	_fragmentShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_fragmentShaderID == 0){
		fatalError("Fragment Shaders failed to be created!");
	}
	   
	std::ifstream vertexFile(vertexShaderFilePath);
	if (vertexFile.fail()){
		fatalError("Failed to open " + vertexShaderFilePath);
	}

}

void GLSLProgram::linkShaders()
{


}
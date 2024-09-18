#include<ft2build.h>
#include FT_FREETYPE_H
#include<map>
#include<vector>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

class CharMap
{
public:
	CharMap()
	{
		FT_Init_FreeType(&ft);
		FT_Face face;
		FT_New_Face(ft, "Font.ttf", 0, &face);
		FT_Set_Pixel_Sizes(face, 0, 48);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		GLuint i = 0;
		while (!FT_Load_Char(face, i, FT_LOAD_RENDER))
		{
			GLuint texture;
			glGenTextures(GL_TEXTURE_2D, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_INT, face->glyph->bitmap.buffer);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			chars.insert(std::pair<char, GLuint>(i, texture));
			i++;
		}

	}

private:
	FT_Library ft;
	std::map<char, GLuint> chars;
};
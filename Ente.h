#pragma once

class Ente
{
private:
	int id;

public:
	Ente();
	~Ente();
	virtual void executar() = 0;
	virtual void imprimirse() = 0;
};
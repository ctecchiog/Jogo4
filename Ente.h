#pragma once

class Ente
{
private:
	int id;

public:
	Ente();
	~Ente();
	virtual void executar();
	virtual void imprimirse();
};
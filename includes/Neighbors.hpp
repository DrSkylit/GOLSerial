class Neighbors{
public:
    Neighbors();
    ~Neighbors(); // destructor
    int getAliveNeighbors();

private:
	struct Direction{
		int i;
		int j;
	};
	struct Direction directions[8];
	void setNeighbors();
};
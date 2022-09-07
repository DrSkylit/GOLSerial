class Cell{
public:
    Cell();
    ~Cell(); // destructor
    void setCell(int row, int column);
    int getRow();
    int getColumn();

private:
	int row;
	int column;
};
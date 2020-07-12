

template <typename t>
t bnode<t>::getEntry() const
{
  return item;
}

template <typename t>
bnode<t> * bnode<t>::getLeft() const
{
  return leftptr;
}

template <typename t>
bnode<t> *bnode<t>::getRight() const
{
  return rightptr;
}

template <typename t>
void bnode<t>::setEntry(t entry)
{
  item=entry;
}

template <typename t>
void bnode<t>::setLeft(bnode<t> *left)
{
  leftptr=left;
}

template <typename t>
void bnode<t>::setRight(bnode<t> *right)
{
  rightptr=right;
}

template <typename t>
bnode<t>::bnode(t entry)
{
  item=entry;
  leftptr=nullptr;
  rightptr=nullptr;
}

template <typename t>
bnode<t>::bnode()
{
  leftptr=nullptr;
  rightptr=nullptr;
}

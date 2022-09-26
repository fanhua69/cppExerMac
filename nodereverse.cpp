

struct node
{
  int n;
  node * next;
};


node * nodereverse(node *p)
{
  if(!p)
  {
    return nullptr;
  }

  node *first = p;
  node *second = p->next;
  if(!second)
  {
    return p;
  }
  first->next = nullptr;

  node * third = nullptr;
  while(second)
  {
    third = second->next;
    second->next = first;
    first = second;
    second = third;
  }

  return first;
}

void nodereversemain()
{
  node a[10];

  int num = sizeof(a) / sizeof(node);
  for(int i=0;i<num;i++)
  {
    a[i].n = i;
    if(i<num-1)
    {
      a[i].next = &a[i+1];
    }
  }

  a[num-1].next = nullptr;

  node *p = nodereverse (a);
}

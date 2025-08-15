#ifndef LIST_HH
#define LIST_HH

#include <string>
#include <memory>

class List {
 public:
   List();

   void add_back(const std::string& insertable_task);
   bool remove_front(std::string& removed_task);
   bool is_empty() const;
   void print() const;

 private:
   struct List_item {
      std::string task;
      std::shared_ptr<List_item> next;
   };

   std::shared_ptr<List_item> first_;
   std::shared_ptr<List_item> last_;
};

#endif

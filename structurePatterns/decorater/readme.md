attach new behaviors to objects by placing these objects inside special wrapper objects that contain the behaviors.
*  Component: declares the common interface for both wrappers and wrapped objects.
*  Concrete Component: a class of objects being wrapped. 
*  Base Decorator: class has a field for referencing a wrapped object. The field’s type should be declared as 
   the component interface so it can contain both concrete components and decorators. The base decorator delegates all operations to the wrapped object.
*  Concrete Decorators: define extra behaviors that can be added to components dynamically.
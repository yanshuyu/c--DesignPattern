Bridge pattern lets you split the monolithic class into several class hierarchies,separation abstraction and implementation, and allow you to change implementation at run time.
* Abstraction: provides high-level control logic, It relies on the implementation object to do the actual low-level work.
* Implementation: declares the interface that’s common for all concrete implementations, An abstraction can only communicate with an implementation object via methods that are declared here.
* Client: only interested in working with the abstraction. However, it’s the client’s job to link the abstraction object with one of the implementation objects.


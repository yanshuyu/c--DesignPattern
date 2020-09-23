allows objects with incompatible interfaces to collaborate.
* Client: Interface describes a protocol that other classes must follow to be able to collaborate with the client
code.
* Service: some useful class (usually 3rd-party or legacy). The client can’t use this class directly because it has an incompatible interface.
* Adapter: class that’s able to work with both the client and the service: it implements the client interface, while wrapping the service object. The adapter receives calls from the client via the adapter interface and translates them into calls to the wrapped service object in a format it can understand
use when have a group of related objects that handle similar events, base on event type.

* event handler: define common interface to handle event, concrete event handler implement the interface to handle concrete event or forward to next event handler.

* client: inject concrete event to specific event handler.
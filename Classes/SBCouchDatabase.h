//
//  SBCouchDatabase.h
//  CouchObjC
//
//  Created by Stig Brautaset on 21/03/2008.
//  Copyright 2008 Stig Brautaset. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "SBCouchDocument.h"

@class SBCouchServer;
@class SBCouchResponse;

/// Interface to a CouchDB database.
@interface SBCouchDatabase : NSObject {
@private
    SBCouchServer *server;
    NSString *name;
}

/// Initialise a database with a server and name.
- (id)initWithServer:(SBCouchServer*)server name:(NSString*)name;

/// The name of the database.
@property (readonly) NSString *name;

/// Query the database in various ways.
- (NSDictionary*)get:(NSString*)args;

- (SBCouchDocument*)getDocument:(NSString*)id withRevisionCount:(BOOL)withCount;

/// Post a document to the database.
- (SBCouchResponse*)postDocument:(NSDictionary*)doc;

/// Put a document to the given name in the database.
- (SBCouchResponse*)putDocument:(NSDictionary*)doc named:(NSString*)x;

/// Put a document into the database. The value of _id will be used for 
/// its name. 
- (SBCouchResponse*)putDocument:(SBCouchDocument*)couchDocument;


/// Delete a document.
- (SBCouchResponse*)deleteDocument:(NSDictionary*)doc;

@end

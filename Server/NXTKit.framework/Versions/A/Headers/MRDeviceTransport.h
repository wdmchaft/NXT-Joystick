//
//  MRDeviceTransport.h
//  DeviceKit
//
//  Copyright Matt Rajca 2010. All rights reserved.
//

@protocol MRDeviceTransportDelegate;

@interface MRDeviceTransport : NSObject {
  @private
	BOOL _open;
	__weak id < MRDeviceTransportDelegate > _delegate;
}

@property (readonly, getter=isOpen) BOOL open;
@property (assign) __weak id < MRDeviceTransportDelegate > delegate;

- (BOOL)open:(NSError **)outError;
- (void)close;

- (BOOL)writeData:(NSData *)data error:(NSError **)outError;

/* these methods should only be called by subclasses to invoke delegate methods */
- (void)receivedData:(NSData *)data;

- (void)opened;
- (void)failedToOpen:(NSError *)error;

- (void)closed;

@end


@protocol MRDeviceTransportDelegate < NSObject >

@optional

- (void)deviceTransport:(MRDeviceTransport *)aTransport didReceiveData:(NSData *)data;

- (void)deviceTransportDidOpen:(MRDeviceTransport *)aTransport;
- (void)deviceTransport:(MRDeviceTransport *)aTransport didFailToOpen:(NSError *)error;

- (void)deviceTransportDidClose:(MRDeviceTransport *)aTransport;

@end

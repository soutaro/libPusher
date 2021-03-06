//
//  LRURLConnectionOperation.h
//  LRResty
//
//  Created by Luke Redpath on 04/10/2010.
//  Copyright 2010 LJR Software Limited. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface PTURLRequestOperation : NSOperation {
  BOOL _isExecuting;
  BOOL _isFinished;
  NSURLRequest *URLRequest;
  NSURLResponse *URLResponse;
  NSURLConnection *URLConnection;
  NSError *connectionError;
  NSMutableData *responseData;
}
@property (nonatomic, retain) NSURLRequest *URLRequest;
@property (nonatomic, retain, readonly) NSURLResponse *URLResponse;
@property (nonatomic, retain, readonly) NSError *connectionError;
@property (nonatomic, retain, readonly) NSData *responseData;

- (id)initWithURLRequest:(NSURLRequest *)request;
- (void)finish;
- (void)cancelImmediately;
@end

@interface PTURLRequestOperation (NSURLConnectionDelegate)
- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)theResponse;
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;
- (void)connectionDidFinishLoading:(NSURLConnection *)connection;
- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error;
@end

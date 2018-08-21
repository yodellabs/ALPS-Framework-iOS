/******************************************************************************
 *  ALPS, The Acoustic Location Processing System.
 *  Copyright (C) 2018, Yodel Labs Inc.
 *  All rights reserved.
 *
 *  This software is the property of Yodel Labs Inc. Source may
 *  be modified, but this license does not allow distribution.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Contributing Author(s):
 *  Patrick Lazik
 *  Nick Wilkerson
 *
 *******************************************************************************/

/**
 * The location manager is the main class used to interface with ALPS. It is
 * responsible for starting, stopping and receiving location updates.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "ALPSLocalLocation.h"
#import "ALPSRangeDataPoint.h"

typedef struct {
    float x;
    float y;
    float z;
    float rotation;
} ALPSPoseTransform;

ALPSPoseTransform alpsPoseTransformMake(float x, float y, float z, float rotation) {
    ALPSPoseTransform transform;
    transform.x = x;
    transform.y = y;
    transform.z = z;
    transform.rotation = rotation;
    return transform;
}

@class ALPSLocationManager, ALPSAudioBeaconFlightData;

@protocol ALPSLocationManagerDelegate <NSObject>

/**
 *  Delegate method that should be used for AR applications. Supplies the current location in the ALPS coordinate system and the transform from ARKit's reference frame to ALPS's reference frame.
 *  @param manager Pointer to the location manager that sent a new location.
 *  @param location The location in the ALPS reference frame with accuracies in meters.
 *  @param poseTransform The pose transform to translate and rotate the ARKit reference from to the ALPS reference frame.
 *  @param rangeDataPoints NSArray containing ALPSRangeDataPoints from received ultrasound transmissions. These each contain a beacon MAC, time slot and range from the phone to the beacon.
 *  @param timeStamp Unix time of when the data was received.
 */
-(void)locationManager:(ALPSLocationManager *)manager
     didUpdateLocation:(ALPSLocalLocation *)location
      andPoseTransform:(ALPSPoseTransform)poseTransform
           fromBeacons:(NSArray<ALPSRangeDataPoint*>*)rangeDataPoints
             timeStamp:(double)timeStamp;


@optional
/**
 *  Delegate method for when the location manager has started running.
 *  @param manager Pointer to the location manager that started.
 */
-(void)locationManagerDidStartUpdatingLocation:(ALPSLocationManager *)manager;

/**
 *  Delegate method for when the location manager has stopped running.
 *  @param manager Pointer to the location manager that started.
 */
-(void)locationManagerDidStopUpdatingLocation:(ALPSLocationManager *)manager;

/**
 *  Delegate method for providing the floor plan image (if any) of where the iOS device is currently located. This image is stored in the realm database.
 *  @param floorPlanImage Image of the floor plan as an UIImage.
 *  @param scale Scale of the floor plan image in meters/pixel.
 *  @param manager Pointer to the location manager that called back.
 */
-(void)locationManager:(ALPSLocationManager *)manager
didUpdateFloorPlanImage:(UIImage *)floorPlanImage
        withPixelScale:(double)scale;


@end

@interface ALPSLocationManager : NSObject


/**
 *  This initializer must be called for the location manager to connect to the Realm database for retreiving beacon configuration and floor plan data.
 *  @param remoteRealmIdentifier Remote Realm Identifer in the form /userid/realmid
 */
-(id)initWithRemoteRealmIdentifier:(NSString *)remoteRealmIdentifier;


/**
 *  Method to start receiving location updates from ALPS. Locations will sent through the <didUpdateLocation> delegate method.
 *  It should be called in viewDidAppear or equivalent
 */
-(void)startUpdatingLocation;

/*
 *  Method to stop location updates.
 */
-(void)stopUpdatingLocation;

/**
 *  This method must be called with the current location coordinates and timestamp provided by ARKit. It should be called from the didUpdate frame:ARFrame delegate method from ARKit.
 *  @param x X coordinate of the current ARFrame provided by ARKit.
 *  @param y Y coordinate of the current ARFrame provided by ARKit.
 *  @param z Z coordinate of the current ARFrame provided by ARKit.
 *  @param timeStamp Time stamp of the current ARFrame provided by ARKit.
 */
-(void)fuseRelativeLocationWithX:(double)x y:(double)y z:(double)z timeStamp:(double)timeStamp;


@property (nonatomic, weak) id <ALPSLocationManagerDelegate> delegate;


@end

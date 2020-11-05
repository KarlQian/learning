/**************************************************************************************************
*
* \file Curl.cpp
* \brief EB C++ Training - Example for the design of testable classes
* 
* Copyright (c) 2013 Elektrobit. All rights reserved.
*
* This file is part of the Elektrobit C++ Training.
*
* Task: Evaluate the following (partial) implementation in the context of testability: How easy
*       is it to write a unit test for verification? Explain your assessment.
*
**************************************************************************************************/

class PlaceDescriptionService
{
 public:
    // ...
    std::string const SummaryDescription( std::string const& latitude, std::string const& longitude ) const;
    std::string const SummaryDescription( std::string const& response ) const;
    std::string const Get( std::string const& requestUrl ) const;
    std::string const CreateRequestUrl( std::string const& latitude, std::string const& longitude ) const;
    std::string const KeyValue( std::string const& key, std::string const& value );
    // ...

 private:
    // ...
    Http* m_http;  // HTTP proxy
    // ...
};


std::string const PlaceDescriptionService::SummaryDescription( std::string const& latitude
                                                             , std::string const& longitude ) const
{
    std::string const request  = CreateRequestUrl( latitude, longitude );
    std::string const response = Get( request );
    return SummaryDescription( response );
}


std::string const PlaceDescriptionService::SummaryDescription( std::string const& response ) const
{
    AddressExtractor extractor;
    const std::string extractor.AddressFrom( response );
    return adress.SummaryDescription();
}


std::string const PlaceDescriptionService::Get( std::string const& requestUrl ) const
{
    return http_->Get( requestUrl );
}


std::string const PlaceDescriptionService::CreateRequestUrl( std::string const& latitude
                                                           , std::string const& longitude ) const
{
    std::string const server  ( "http://open.mapquestapi.com/" );
    std::string const document( "nominatim/v1/reverse" );
    return server + document + "?" + KeyValue( "format", "json" ) + "&" +
                                   + KeyValue( "lat", latitude  ) + "&" +
                                   + KeyValue( "lon", longitude );
}


std::string const PlaceDescriptionService::KeyValue( std::string const& key, std::string& value ) const
{
    return key + "=" + value;
}

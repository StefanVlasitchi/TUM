﻿namespace MovieAPI.Settings
{
    public interface IMongoDbSettings
    {
        string ConnectionString { get; set; }
        string Database { get; set; }
    }
}

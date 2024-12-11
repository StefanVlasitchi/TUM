﻿using Common.Models;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using MovieAPI.Repositories;
using MovieAPI.Services;

namespace MovieAPI.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class MovieController : ControllerBase
    {
        private readonly IMongoRepository<Movie> _movieRepository;
        private readonly ISyncService<Movie> _movieSyncService;
        public MovieController(IMongoRepository<Movie> movieRepository,
            ISyncService<Movie> movieSyncService)
        {
            _movieRepository = movieRepository;
            _movieSyncService = movieSyncService;
        }


        [HttpGet]
        public List<Movie> GetAllMovies()
        {
            var response = _movieRepository.GetAllRecords();
            return response;
        }


        [HttpGet("{id}")]
        public Movie GetMovieById(Guid id)
        {
            var movie = _movieRepository.GetRecordById(id);

            return movie;
        }


        [HttpPost]
        public IActionResult Create(Movie movie)
        {
            movie.LastChangedAt = DateTime.UtcNow;

            var response = _movieRepository.InsertRecord(movie);

            _movieSyncService.Upsert(movie);

            return Ok(response);
        }


        [HttpDelete("{id}")]
        public IActionResult Delete(Guid id)
        {
            var movie = _movieRepository.GetRecordById(id);
            if(movie == null)
            {
                return BadRequest("Movie does not Exist!");
            }

            _movieRepository.DeleteRecord(id);

            movie.LastChangedAt = DateTime.UtcNow;
            _movieSyncService.Delete(movie);


            return Ok("Deleted " + id);
        }

        [HttpDelete("sync")]
        public IActionResult DeleteSync(Movie movie)
        {
            var existingMovie = _movieRepository.GetRecordById(movie.Id);
            if (existingMovie != null || movie.LastChangedAt > existingMovie.LastChangedAt)
            {
                _movieRepository.DeleteRecord(movie.Id);
            }

            return Ok();
        }

        [HttpPut]
        public IActionResult Upsert(Movie movie)
        {
            if (movie.Id == Guid.Empty)
            {
                return BadRequest("Empty Id");
            }

            movie.LastChangedAt = DateTime.UtcNow;
            _movieRepository.UpsertRecord(movie);

            _movieSyncService.Upsert(movie);

            return Ok(movie);
        }

        [HttpPut("sync")]
        public IActionResult UpsertSync (Movie movie)
        {
            var existingMovie = _movieRepository.GetRecordById(movie.Id);
            if( existingMovie == null || movie.LastChangedAt > existingMovie.LastChangedAt)
            {
                _movieRepository.UpsertRecord(movie);
            }

            return Ok();
        }


    }
}

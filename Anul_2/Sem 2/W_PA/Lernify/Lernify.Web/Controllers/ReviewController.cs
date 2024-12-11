using AutoMapper;
using Lernify.Web.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.Review;


namespace Lernify.Web.Controllers
{
     public class ReviewController : BaseController
     {
          private readonly IReview _reviewBL;
          public ReviewController()
          {
               var bl = new BusinessLogic.BusinessLogic();
               _reviewBL = bl.GetReviewBL();
          }
          // GET: Contact
          public ActionResult Index()
          {
               SessionStatus();
               ReviewModel model = new ReviewModel();
               if (System.Web.HttpContext.Current.Session["LoginStatus"] == "login")
               {
                    model.Name = ViewBag.CurrentUser.Username;
                    model.Email = ViewBag.CurrentUser.Email;
               }
               else
               {
                    model.Name = null;
                    model.Email = null;
               }
               return View(model);
          }

          [HttpPost]
          public ActionResult Index(ReviewModel review)
          {
               SessionStatus();

               if (ModelState.IsValid)
               {
                    var config = new MapperConfiguration(cfg =>
                    {
                         cfg.CreateMap<ReviewModel, Review>();
                    });
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<Review>(review);

                    data.Date = DateTime.Now;

                    _reviewBL.AddReview(data);
                    return RedirectToAction("Index");//edit this
               }
               return View();
          }

         

          public ActionResult Reviews()
          {
               SessionStatus();
               var config = new MapperConfiguration(cfg =>
               {
                    cfg.CreateMap<ReviewModel, Review>();
               });
               IMapper mapper = config.CreateMapper();

               var reviews = mapper.Map<List<Review>>(_reviewBL.GetReviews());
               return View(reviews);
          }
     }
}
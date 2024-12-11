using Lernify.BusinessLogic.Core;
using System.Collections.Generic;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.Review;

namespace Lernify.BusinessLogic.Implementation
{
     public class ReviewBL : UserApi, IReview
     {
          public void AddReview(Review review)
          {
              
               AddNewReview(review);
          }

          public List<Review> GetReviews()
          {
               return GetReviewList();
          }
     }
}
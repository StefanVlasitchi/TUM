using Lernify.BusinessLogic.Implementation;
using Lernify.BusinessLogic.Interfaces;

namespace Lernify.BusinessLogic
{
     public class BusinessLogic
     {
          public ISession GetSessionBL()
          {
               return new SessionBL();
          }

          public ICourse GetCourseBL()
          {
               return new CourseBL();
          }

          public IUser GetUserBL()
          {
               return new UserBL();
          }

          public ITeacher GetTeacherBL()
          {
               return new TeacherBL();
          }

          public IReview GetReviewBL()
          {
               return new ReviewBL();
          }
          public IEnrollCourses GetEnrollCoursesBl()
          {
               return new EnrollCoursesBL();
          }
     }
}

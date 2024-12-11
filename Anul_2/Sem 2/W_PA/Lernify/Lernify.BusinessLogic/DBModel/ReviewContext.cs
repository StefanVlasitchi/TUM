using System.Data.Entity;
using Lernify.Domain.Entities.Review;

namespace Lernify.BusinessLogic.DBModel
{
     public class ReviewContext:DbContext
     {
          
               public ReviewContext() :
                    base("name=Lernify")
               { }

               public virtual DbSet<RDbTable> Reviews { get; set; }
          
     }
}
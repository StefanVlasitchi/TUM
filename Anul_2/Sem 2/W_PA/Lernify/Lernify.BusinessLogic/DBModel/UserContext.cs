using Lernify.Domain.Entities.User;
using System.Data.Entity;

namespace Lernify.BusinessLogic.DBModel
{
     public class UserContext : DbContext
     {
          public UserContext() : base("name=Lernify")
          {

          }
          public virtual DbSet<UDbTable> Users { get; set; }
     }
}

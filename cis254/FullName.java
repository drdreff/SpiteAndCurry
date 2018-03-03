
class FullName{
  private String given;
  private String family;

  public FullName(String p1, String p2 ){
    given = p1;
    family = p2;
  }
  public String toString(){
    return family +", "+ given;
  }
}

/**
 * Created with IntelliJ IDEA.
 * User: Matt
 * Date: 4/17/13
 * Time: 8:26 PM
 * To change this template use File | Settings | File Templates.
 */

/**
 * Simple interface that a subject uses to notify an
 * observer when the state of the subject has changed
 */
public interface Observer
{
    void update(String message) throws Exception;
}


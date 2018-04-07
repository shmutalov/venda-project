-----------------------------------------------------------------------------
ABOUT Track Field Changes
-----------------------------------------------------------------------------
The Track Field Changes enable to track/audit easily all the fields updates.

The module does not use the default Drupal versioning system.
The system will save the time, the user,
the value before and after each modification on a field.

-----------------------------------------------------------------------------
CURRENT FEATURES
-----------------------------------------------------------------------------

    Select which content type need to be audited
    Select which fields need to be audited
    Integration with view

Supported fields :

    Title
    Body
    Boolean
    Date
    Date ISO
    Date Unix
    Decimal
    File (Limited support)
    Email
    Float
    Image (Limited support)
    Integer
    Link
    List (float)
    List (integer)
    List (text)
    Lon Text
    Term reference
    Text
    User reference
    GeoField
    Entity reference

-----------------------------------------------------------------------------
INSTALLATION
-----------------------------------------------------------------------------

1. Download and Enable the module

-----------------------------------------------------------------------------
USAGE
-----------------------------------------------------------------------------

1.  Set up the fields and content type you would like to audit:
    /admin/config/system/track_field_changes

2.  Create a view showing the content type that your are tracking and add the
    'Track Field Changes' fields. Types of field available are:

    Field Tracker: Creation Date
        This is the creation date of the revison. Displays the time and date the
        field was updated.

    Field Tracker: Field Name
        Displays the machine name for the field with tracking enabled.

    Field Tracker: Track Changes Log
        The log message entered when the field was changed.

    Field Tracker: Track Changes Type
        Possible values are:
            bn - A new node is being inserted.
            br - A node is being updated with the Basic audit enabled.
                 One entry per updated node.
            fr - A node is being updated and field tracking is enabled.
                One entry per field with tracking enabled.

    Field Tracker: User
        The user who updated the field.

    Field Tracker: Value After
        The value after the update.

    Field Tracker: Value Before
        The value before the update.

-----------------------------------------------------------------------------
Future Roadmap
-----------------------------------------------------------------------------

    Enable track changes on every entity (user,..)

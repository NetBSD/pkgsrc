$NetBSD: patch-lib_CGI_FormBuilder_Field.pm,v 1.1 2014/10/14 14:43:09 schmonz Exp $

Avoid unneeded warning from CGI.pm 4.05 or newer.

--- lib/CGI/FormBuilder/Field.pm.orig	2007-03-02 18:13:14.000000000 +0000
+++ lib/CGI/FormBuilder/Field.pm
@@ -189,7 +189,7 @@ sub cgi_value {
     my $self = shift;
     debug 2, "$self->{name}: called \$field->cgi_value";
     puke "Cannot set \$field->cgi_value manually" if @_;
-    if (my @v = $self->{_form}{params}->param($self->name)) {
+    if (my @v = @{$self->{_form}{params}->param_fetch($self->name)}) {
         for my $v (@v) {
             if ($self->other && $v eq $self->othername) {
                 debug 1, "$self->{name}: redoing value from _other field";

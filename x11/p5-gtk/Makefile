# $NetBSD: Makefile,v 1.14 2001/02/17 17:06:38 wiz Exp $
#

DISTNAME=		Gtk-Perl-0.7003
PKGNAME=		p5-gtk-0.7003
CATEGORIES=		x11 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Gtk/} \
			ftp://ftp.gtk.org/pub/gtk/perl/

MAINTAINER=		root@garbled.net
COMMENT=		Perl bindings for GTK+

DEPENDS+=		gtk+-1.2.*:../../x11/gtk

USE_X11=		# defined
USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Gtk/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

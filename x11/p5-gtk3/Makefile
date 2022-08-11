# $NetBSD: Makefile,v 1.4 2022/08/11 05:09:32 gutteridge Exp $

DISTNAME=	Gtk3-0.038
PKGNAME=	p5-${DISTNAME:S/Gtk/gtk/}
PKGREVISION=	3
CATEGORIES=	x11 perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/X/XA/XAOC/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Perl bindings for Gtk3
LICENSE=	gnu-lgpl-v2

DEPENDS+=	p5-Carp>=0:../../devel/p5-Carp
DEPENDS+=	p5-Glib-Object-Introspection>=0.043:../../devel/p5-Glib-Object-Introspection

PERL5_PACKLIST=	auto/Gtk3/.packlist
USE_LANGUAGES=	# none

.include "../../graphics/p5-cairo-gobject/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

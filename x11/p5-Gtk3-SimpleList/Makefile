# $NetBSD: Makefile,v 1.10 2023/11/14 14:03:18 wiz Exp $

DISTNAME=	Gtk3-SimpleList-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	x11 perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/T/TV/TVIGNAUD/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/soig/Gtk3-SimpleList
COMMENT=	Easy-to-use Gtk3 list widget
LICENSE=	gnu-lgpl-v2

PERL5_PACKLIST=	auto/Gtk3/SimpleList/.packlist
USE_LANGUAGES=	# none

.include "../../x11/p5-gtk3/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

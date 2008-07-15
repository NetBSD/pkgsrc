# $NetBSD: Makefile,v 1.17 2008/07/15 12:16:09 rhaen Exp $
#

DISTNAME=	XML-Writer-0.604
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xwr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://xml-writer-perl.berlios.de/
COMMENT=	Perl module for writing XML documents

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/Writer/.packlist
PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

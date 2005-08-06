# $NetBSD: Makefile,v 1.13 2005/08/06 06:19:34 jlam Exp $
#

DISTNAME=	XML-Writer-0.530
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xwr
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xml-writer-perl.berlios.de/
COMMENT=	Perl module for writing XML documents

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/Writer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

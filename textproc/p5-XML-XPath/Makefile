# $NetBSD: Makefile,v 1.9 2004/04/20 21:00:55 minskim Exp $

DISTNAME=	XML-XPath-1.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xxp
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sergeant.org/
COMMENT=	XML XPath software

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

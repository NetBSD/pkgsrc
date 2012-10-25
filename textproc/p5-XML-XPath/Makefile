# $NetBSD: Makefile,v 1.23 2012/10/25 06:56:42 asau Exp $

DISTNAME=	XML-XPath-1.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
SVR4_PKGNAME=	p5xxp
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-XPath/
COMMENT=	XML XPath software

DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

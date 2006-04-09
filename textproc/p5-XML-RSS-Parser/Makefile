# $NetBSD: Makefile,v 1.8 2006/04/09 01:01:19 schmonz Exp $

DISTNAME=	XML-RSS-Parser-4.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	schmonz@NetBSD.org
COMMENT=	Liberal object-oriented parser for RSS feeds

DEPENDS+=	p5-XML-SAX-[0-9]*:../../textproc/p5-XML-SAX
DEPENDS+=	p5-Class-XPath>=1.4:../../devel/p5-Class-XPath
DEPENDS+=	p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/XML-RSS-Parser-4

PERL5_PACKLIST=		auto/XML/RSS/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

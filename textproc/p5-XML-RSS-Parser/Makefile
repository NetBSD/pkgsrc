# $NetBSD: Makefile,v 1.6 2006/01/24 07:32:37 wiz Exp $

DISTNAME=	XML-RSS-Parser-2.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	schmonz@NetBSD.org
COMMENT=	Liberal object-oriented parser for RSS feeds

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Class-XPath>=1.4:../../devel/p5-Class-XPath

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/RSS/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

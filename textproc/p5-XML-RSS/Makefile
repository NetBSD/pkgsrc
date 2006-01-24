# $NetBSD: Makefile,v 1.13 2006/01/24 07:32:37 wiz Exp $

DISTNAME=	XML-RSS-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5xrs
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-RSS/
COMMENT=	XML-RSS helps to create and update RSS files

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser

PERL5_PACKLIST=		auto/XML/RSS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

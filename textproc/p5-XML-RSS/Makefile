# $NetBSD: Makefile,v 1.9 2005/04/11 21:47:40 tv Exp $

DISTNAME=	XML-RSS-0.97
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xrs
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.pobox.com/~eisen/
COMMENT=	XML-RSS helps to create and update RSS files

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/RSS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

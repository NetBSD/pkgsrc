# $NetBSD: Makefile,v 1.1.1.1 2004/11/12 06:40:39 erh Exp $

DISTNAME=	XML-UM-0.01
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-UM-0.01/
COMMENT=	Convert UTF-8 strings to any encoding supported by XML::Encoding

DEPENDS+=	p5-XML-Encoding>=1.01:../../textproc/p5-XML-Encoding

USE_BUILDLINK3=		YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/UM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

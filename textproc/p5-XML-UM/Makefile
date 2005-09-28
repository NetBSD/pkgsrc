# $NetBSD: Makefile,v 1.7 2005/09/28 14:31:09 rillig Exp $

DISTNAME=	XML-UM-0.01
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-UM-0.01/
COMMENT=	Convert UTF-8 strings to any encoding supported by XML::Encoding

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-Encoding>=1.01:../../textproc/p5-XML-Encoding

PERL5_PACKLIST=	auto/XML/UM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

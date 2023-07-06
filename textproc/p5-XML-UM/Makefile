# $NetBSD: Makefile,v 1.29 2023/07/06 09:42:05 wiz Exp $

DISTNAME=	XML-UM-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	19
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release//XML-UM-0.01
COMMENT=	Convert UTF-8 strings to any encoding supported by XML::Encoding

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-Encoding>=1.01:../../textproc/p5-XML-Encoding

PERL5_PACKLIST=	auto/XML/UM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

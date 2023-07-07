# $NetBSD: Makefile,v 1.49 2023/07/07 11:52:42 jperkin Exp $

DISTNAME=	XML-XPath-1.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-XPath
COMMENT=	XML XPath software
LICENSE=	artistic-2.0

DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Path-Tiny>=0.076:../../filesystems/p5-Path-Tiny

PERL5_PACKLIST=		auto/XML/XPath/.packlist

REPLACE_PERL+=	examples/xpath

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

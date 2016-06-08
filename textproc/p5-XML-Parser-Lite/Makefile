# $NetBSD: Makefile,v 1.3 2016/06/08 19:24:44 wiz Exp $

DISTNAME=	XML-Parser-Lite-0.721
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-ParserLite/
COMMENT=	Lightweight regexp-based XML parser
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/XML/Parser/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

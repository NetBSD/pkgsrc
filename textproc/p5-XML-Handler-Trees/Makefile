# $NetBSD: Makefile,v 1.21 2024/11/16 12:07:08 wiz Exp $

DISTNAME=	XML-Handler-Trees-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Handler-Trees
COMMENT=	PerlSAX handlers for building tree structures

PERL5_PACKLIST=		auto/XML/Handler/Trees/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

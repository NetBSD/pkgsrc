# $NetBSD: Makefile,v 1.20 2023/07/06 09:42:02 wiz Exp $

DISTNAME=	XML-Handler-Trees-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Handler-Trees
COMMENT=	PerlSAX handlers for building tree structures

PERL5_PACKLIST=		auto/XML/Handler/Trees/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

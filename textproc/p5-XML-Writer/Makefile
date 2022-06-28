# $NetBSD: Makefile,v 1.42 2022/06/28 11:36:45 wiz Exp $

DISTNAME=	XML-Writer-0.900
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://xml-writer-perl.berlios.de/
COMMENT=	Perl module for writing XML documents
#LICENSE=	?
# Redistribution and use in source and compiled forms, with or without
# modification, are permitted under any circumstances.  No warranty.

PERL5_PACKLIST=		auto/XML/Writer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

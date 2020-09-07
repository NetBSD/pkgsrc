# $NetBSD: Makefile,v 1.9 2020/09/07 17:52:57 wiz Exp $

DISTNAME=	POSIX-strftime-Compiler-0.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POSIX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/POSIX-strftime-Compiler
COMMENT=	Perl extension for glibc compatible strftime for loggers/servers
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build::Tiny

PERL5_PACKLIST=	auto/POSIX/strftime/Compiler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"

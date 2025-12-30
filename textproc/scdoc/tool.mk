# $NetBSD: tool.mk,v 1.1 2025/12/30 16:01:23 kikadf Exp $
#
# This mk fragment can be included in all packages that uses `scdoc'
# as a tool.
#
# Keywords: scdoc
#

.if !defined(SCDOC_TOOL_MK)
SCDOC_TOOL_MK=	defined

BUILDLINK_TARGETS+=	buildlink-bin-scdoc buildlink-pkgconfig-scdoc

.PHONY: buildlink-bin-scdoc
buildlink-bin-scdoc:
	${RUN} \
	f="${PREFIX}/bin/scdoc"; \
	d="${BUILDLINK_DIR}/bin"; \
	t="$$d/scdoc"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${MKDIR} -p $$d; \
		${LN} -sf $$f $$t; \
	fi

.PHONY: buildlink-pkgconfig-scdoc
buildlink-pkgconfig-scdoc:
	${RUN} \
	f="${PREFIX}/share/pkgconfig/scdoc.pc"; \
	d="${BUILDLINK_DIR}/share/pkgconfig"; \
	t="$$d/scdoc.pc"; \
	if ${TEST} -f $$f -a ! -f $$t ; then \
		${MKDIR} -p $$d; \
		${LN} -sf $$f $$t; \
	fi

.endif # SCDOC_TOOL_MK
